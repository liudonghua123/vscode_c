# vscode_c

This is a template vscode c project for windows platform.

### How to use

1. git clone https://github.com/liudonghua123/vscode_c.git
2. open in vscode (`code vscode_c`)
3. write your program
4. press F5 to debug (the executable is generated under `bin` directory)
5. (optional) edit `.vscode/launch.json`/`.vscode/tasks.json`/`.vscode/settings.json` to make some customization.

### Prerequisites

Because the template project use `MSYS2` and `gcc`, so you need to install first. Then configure `C:\msys32\mingw32\bin` and `C:\msys32\usr\bin` to your PATH environment variable.

### Features

1. use google code style to format the code when save source file
2. customize the integrated terminal to use cmd
3. customize the font used in editor and integrated terminal

### Some other tips

If you would rather use `make` to compile your program, change to `makefile` branch.

### License

MIT
