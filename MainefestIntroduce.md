### Introduction
zephyr项目中包含一个west工具，它提供了一个多repo管理系统，也可以用来构建程序，烧写程序，调试应用程序。

### Workspace
```
zephyrproject/                 # west topdir
├── .west/                     # marks the location of the topdir
│   └── config                 # per-workspace local configuration file
│
│   # The manifest repository, never modified by west after creation:
├── zephyr/                    # .git/ repo
│   ├── west.yml               # manifest file
│   └── [... other files ...]
│
│   # Projects managed by west:
├── modules/
│   └── lib/
│       └── tinycbor/          # .git/ project
├── net-tools/                 # .git/ project
└── [ ... other projects ...]
```

### How to add user repo
修改west.yml文件，仿照remotes部分，添加name和url-base,其中name是user对添加的remote的自定义命名，将在下面使用，url-base是user的github link，注意不是对应repo的link。然后在project中添加user需要添加的工程，需要添加name,remote,revision,path,这里的name指的是url-base中需要添加到这里的repo名字，remote便是remotes部分添加的name对应的值，因为zephyr有默认的remote，因此，需要特别指明，否则将访问出错。revision指的是需要添加repo的哪个点，可以是commit hash值，也可以是"main";path则是指定添加的工程放在什么路径下，这里需要注意的是，west默认的根目录是zephyrproject这个文件夹，因此需要从改路径下开始指定。

* Reference

https://docs.zephyrproject.org/latest/guides/west/manifest.html
