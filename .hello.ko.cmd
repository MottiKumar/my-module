cmd_/home/zos-m1/Documents/my-module/hello.ko := ld -r -m elf_x86_64 -z noexecstack --no-warn-rwx-segments --build-id=sha1  -T arch/x86/module.lds -o /home/zos-m1/Documents/my-module/hello.ko /home/zos-m1/Documents/my-module/hello.o /home/zos-m1/Documents/my-module/hello.mod.o;  true
