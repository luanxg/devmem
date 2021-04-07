## devmem

RT-Thread 上的 MCU/CPU 读写内存/寄存器的小工具，在menuconfig里选中软件包后，在msh上输入`devmem`查看使用说明。

```
msh />devmem

Usage:  devmem address [type [data]]
        address : memory address to act upon
        type    : access operation type : [b]yte, [h]alfword, [w]ord
        data    : data to be written
```
### 写内存/寄存器

#### byte方式写入

```
devmem 0x600a4000 b 0xa
```

#### halfword方式写入

```
devmem 0x600a4000 h 0xab
```

#### word方式写入

```
devmem 0x600a4000 w 0xabcd
```

### 读内存/寄存器

#### byte方式读取

```
msh />devmem 0x600a4000 b
0x0a
```

#### halfword方式读取

```
msh />devmem 0x600a4000 h
0x00ab
```

#### word方式读取

```
msh />devmem 0x600a4000 w
0x0000abcd
```