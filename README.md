<a id="readme-top" name="readme-top"></a>

<!-- ------------------------------
* TITLE, DESCRIPTION & CONTACT
------------------------------ -->
# ✒️ ft_printf

<table>
    <tr>
        <th align="left" width="3333px">Score</th>
        <th align="left" width="3333px">Duration</th>
        <th align="left" width="3333px">Peer(s)</th>
    </tr>
    <tr>
        <td>✅ <b>125</b> / 100</td>
        <td>🕓 2 week(s)</td>
        <td>👷🏻 No</td>
    </tr>
</table>

<br>

This project is an implementation of the `printf` function from the **Standard Library**, including **several type conversions** and **all existing flags**. The aim is to learn **string manipulation**, **data structures** and **variadic arguments**.

[**⛓️ FILE : SUBJECT**](en.subject.pdf)

<br>

<!-- ------------------------------
* TABLE OF CONTENTS
------------------------------ -->
## 📋 Table of contents

- [**👀 Overview**](#readme-overview)
- [**📦 Requirements**](#readme-requirements)
- [**💾 Installation**](#readme-installation)
- [**⚡️ Usage**](#readme-usage)
- [**🛠️ Makefile**](#readme-makefile)
- [**📄 License**](#readme-license)

<a id="readme-overview" name="readme-overview"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* OVERVIEW
------------------------------ -->
## 👀 Overview

### Features

- Writes formatted data to standard output.
- Supports `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X` and `%` type conversions.
- Supports `-`, `0`, `.`, `#`,` ` and `+` flags and **minimum field width** in all combinations.
- Returns the number of characters written to standard output.

<a id="readme-requirements" name="readme-requirements"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* REQUIREMENTS
------------------------------ -->
## 📦 Requirements

```
sudo apt -y install clang-12 make
```

<a id="readme-installation" name="readme-installation"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* INSTALLATION
------------------------------ -->
## 💾 Installation

**1. Get the project**

```
git clone https://github.com/rilemko/42-ft_printf.git
```

<br>

**2. Build the project**

```
make -j$(nproc)
```

> **🔵 Info:** The `libftprintf.a` archive will be created in the project root directory.

<a id="readme-usage" name="readme-usage"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* USAGE
------------------------------ -->
## ⚡️ Usage

**Example:**

```c
#include "includes/ft_printf.h"

int main(void)
{
    ft_printf("%-10s %s %c\n", "Hello", "world", '!');
    ft_printf("%+d %+.3i %3u %%\n", 1, -2, 3);
    ft_printf("%#x %p\n", 100000, "a");

}
```

```console
$ ./a.out
Hello      world !
+1 -002   3 %
0x186a0 0x555564ee1004
```

<a id="readme-makefile" name="readme-makefile"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* MAKEFILE
------------------------------ -->
## 🛠️ Makefile

<table>
    <tr>
        <th align="left" width="500px">Rule</th>
        <th align="left" width="9500px">Action</th>
        </tr>
    <tr><td><code>all</code></td><td>Compile.</td></tr>
    <tr><td><code>clean</code></td><td>Delete all generated object files</td></tr>
    <tr><td><code>fclean</code></td><td>Apply <code>clean</code>, <code>lclean</code> and delete the archive.</td></tr>
    <tr><td><code>lclean</code></td><td>Apply <code>fclean</code> to all used libraries.</td></tr>
    <tr><td><code>re</code></td><td>Apply <code>fclean</code> and force recompile.</td></tr>
</table>

[**⛓️ FILE : MAKEFILE**](Makefile)

<a id="readme-license" name="readme-license"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* LICENSE
------------------------------ -->
## 📄 License

This project is licensed under the terms of the **MIT** license.

[**⛓️ FILE : LICENSE**](LICENSE.md)

<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>
