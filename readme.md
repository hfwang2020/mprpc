# !!! mprpc = muduo + protobuf !!!

## rpc框架
- MpRpcApplication:
框架入口，负责加载配置文件，单例模式设计

- MpRpcConfig:
封装配置文件

- RpcProvider:
包含一个service句柄的map,根据config启动muduo::TcpServer,注册服务protobuf::service的派生类到map

绑定tcpsever连接和读写回调

读写回调解析buffer，反序列化接收RPC请求

- Rpc请求网络结构
rpc请求头大小+rpchead+用户自定义参数

rpc_head是框架提供的probuffmesage => |service_name|method_name|args_size|
args 需要用户自定义

| rpc_head_size | service_name | method_name | args_size | args |

- RpcChannel:
传入sevice_stub供调用方使用。一个序列化request发送，接收回调函数负责反序列化，

- LogQueue:
异步日志队列 单例模式
两种日志级别
入队线程之间用互斥锁保证线程安全。
一个出队线程如果队列不为空直接出队列，为空用条件变量阻塞等待唤醒。

