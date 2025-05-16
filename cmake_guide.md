# CMake Installation Guide

CMake is a cross-platform build system that automatically generates the necessary build files (like Makefiles or Visual Studio projects) to compile your code.

## Windows

There are several ways to install CMake on windows. The recommended way is via MSYS2 MinGW-64. To install you may follow the guide [here](https://www.msys2.org/).

> *Para el becario*: Ya deberías de tener instalado este programa, es el que recomienda Benji para instalar los compiladores de GCC en Windows.

Once installed open the terminal (MSYS2 MinGW-64's terminal) and run the following two commands:

```{bash}
pacman -Syu
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake make
```

With this CMake should be successfully installed. 

## MacOS

The recommended way to install CMake on MacOS is via Homebrew. If you don't already have it installed, you may install it [here](https://brew.sh/).

Once installed open a terminal session and run:

```{sh}
brew install cmake
```

## Linux

The easiest way to install CMake in via your distro's package manager. You may find the exact command via a simple Google search. Here are some commands for certain distros:

- **Debian/Ubuntu**:

```{sh}
sudo apt update
sudo apt install cmake
```

- **Fedora**:

```{sh}
sudo dnf install cmake
```

- **Arch Linus**:

```{sh}
sudo pacman -S cmake
```

- **OpenSUSE**:

```{sh}
sudo zypper install cmake
```

