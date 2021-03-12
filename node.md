# 1. 需求池
----
- 指令编码可以进行，但是对长指令的处理，中间可能会有那些问题的调研，还没完成。**完成**
- 数据库-节点树的操作基础调研完成，未能绑定业务数据。[DONE] **完成**
- 指令解码未完成 [DONE] **待补充，已经形成固定的开发框架，一般需求**
- spliter的交互逻辑未完成 [DELAY] **待优化**
- view对象，TcpClient对象没有改造完成。[DONE] **完成**
- config设计方案没有确定。[DONE] **完成**
- 工具栏的和书节点的选择交互逻辑未确定 **一般需求**
- - 选中连接节点时工具栏的状态
- - 选中数据库节点时工具栏的状态
- - 选中数据节点时工具栏的状态 
- 整体外观设计 **一般需求**
- 资源文件的多语言版本 [DELAY] **一般需求**
- 多语言版本的实时控制 [DELAY] **一般需求**
- 页面布局的动态适配，计算逻辑优化，现在都是通过硬编码进行布局计算的。**待优化**
- MDI的窗口机制引入. **不需要了,废弃**

# 2. 当前开发任务
---
## 2.1 连接管理机制。**紧急**
- 支持并发连接，同时连接到多个服务器节点.
- 能够在不同的服务连接上自由安全地切换
- 通过心跳包，维持稳定的连接。失效时提示，能够重新连接。
## 2.2 解决粘包问题
## 2.3 清理掉内存问题，
## 数据编辑器未完成，准备实行的方案未确定。[DONE] **紧急需求**

# 3. 功能调研与功能规划
-------
## 1. 选中数据节点时，在数据区展示数据的类型，数据的键值。
## 2. 不同类型的数据怎么编辑?
  - 二进制
  - json
  - 文本
## 3. 数据根据不同的类型，导出成不同的方式
  - 二进制方式
  - json
  - csv
## 4. 布局设计
  - 数据节点上的操作，怎么规划
  - 数据库节点上的操作，怎么规划
## 5. 网络功能增强
  - 多连接支持
  - 断线支持
    - 心跳包功能加入
## 6. 数据增强
  - 数据传输支持大容量的数据。
  - 操作交互支持大容量的数据。
## 7. 连接配置
  - 新增连接的配置和保存
  - SSL连接的支持
## 8. 不同数据类型的操作支持
### 通用操作
- 查看内容
- 删除
- 查看TTL
- 更新TTL
### 字符串,整数
- 增减
- 编辑内容
### 列表
- 添加项目
- 删除项目
- 编辑项目内容
### Hash
- 添加项目
- 删除项目
- 更新项目内容
### set
- 添加项目
- 删除项目
- 更新项目内容
### zset
- 添加项目
- 删除项目
- 更新项目内容

## 9. 性能监控维度的支持
通过表格展示不同维度的信息即可，可以添加字段功能说明。 
## 10. 数据Key的过滤机制，这么应对大量key的问题？
调研数据分页算法
## 11. 中英文支持
已经实现了语言切换的案例。

# 4. Redis功能相关
## 1. 关于redis的密码认证
### 初始化Redis密码,在配置文件中配置,重启生效。
```
  requirepass test123；
```
  redis的查询速度是非常快的，外部用户一秒内可以尝试多大150K个密码；所以密码要尽量长（对于DBA 没有必要必须记住密码）；

### 不重启Redis设置密码
```
   config set requirepass test123
   config get requirepass
   auth test123
```

### 登录有密码的Redis
```
   redis-cli -p 6379 -a test123
```

## 2. Redis常用操作集合
### zset的操作
```
   zadd wangzh 1 redis
   zadd name   2 redis
   zadd age    2 waht
   zadd times  3 addd
   // 查看ZSET里的所有元素
   zrange names 0 -1 withscores
```
## 3. 关于redis被攻击后怎么恢复的问题
TODO 

# 5. 开发技能
## 5.1 gdb的操作
   1. 设置断点 b main.c:352
   2. 下一步   n(next)
## 5.2 内存问题怎么检测

# 6. 开发辅助资料
## 事件处理
```
		case WM_PAINT:
			//hdc = BeginPaint(hWin,&ps);
			//Rectangle(hdc,200,40,260,60);
			//Rectangle(hdc,200,100,260,120);
			//EndPaint(hWin,&ps);
		break;

    windowsx.h里面有很多针对普通组件的消息处理，有详细的文档描述。
    https://docs.microsoft.com/en-us/windows/win32/controls/bm-setcheck
```

## 外部程序调用
```
    ShellExecute(_hwnd,"open","dev.exe","","",SW_NORMAL);
```

# 数据连接处理操作流程
## 1. 选择连接菜单
## 2. 选择配置好的连接
- 创建连接，创建主机树节点。
- 如果需要的话，完成连接认证。
- 取得数据库个数信息，创建数据库树节点。
- 展开树节点，呈现数据库节点列表。
- 双击数据库节点，取得并展现数据节点。