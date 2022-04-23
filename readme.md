# mprpc = muduo + protobuf !!!

依赖库:mprpc muduo_net muduo_base pthread zookeeper_mt
```
github.com/AlDanial/cloc v 1.82  T=0.03 s (2148.0 files/s, 384486.2 lines/s)
-------------------------------------------------------------------------------
Language                     files          blank        comment           code
-------------------------------------------------------------------------------
C++                             11            455            247           2661
C/C++ Header                    10            291            189           1894
JSON                             6              0              0           1601
C                                1            114             50            507
CMake                           16             93             52            467
make                             5            275            208            427
Protocol Buffers                 2             14              5             49
Markdown                         2             16              0             41
Bourne Shell                     1              2              0              8
-------------------------------------------------------------------------------
SUM:                            54           1260            751           7655
-------------------------------------------------------------------------------
```


## rpc框架
- MpRpcApplication:框架入口，负责加载配置文件，单例模式设计

- MpRpcConfig: 封装配置文件

- RpcProvider: 包含一个service句柄的map,根据config启动muduo::TcpServer,注册服务protobuf::service的派生类到map绑定tcpsever连接和读写回调，读写回调解析buffer，反序列化接收RPC请求

- Rpc请求网络结构: rpc请求头大小+rpchead+用户自定义参数

rpc_head是框架提供的probuffmesage 
|service_name|method_name|args_size|

args 需要用户自定义

| rpc_head_size | service_name | method_name | args_size | args |

- RpcChannel: 传入sevice_stub供调用方使用。一个序列化request发送，接收回调函数负责反序列化，

- LogQueue:
异步日志队列 单例模式 提供两种日志级别
入队线程之间用互斥锁保证线程安全。
一个出队线程如果队列不为空直接出队列，为空用条件变量阻塞等待唤醒。

