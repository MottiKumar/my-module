cmd_/home/zos-m1/Documents/my-module/hello.mod := printf '%s\n'   hello.o | awk '!x[$$0]++ { print("/home/zos-m1/Documents/my-module/"$$0) }' > /home/zos-m1/Documents/my-module/hello.mod
