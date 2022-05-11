# Copyright Fixer

<p align="center"><img src="res/CopyrighFixerBanner_web.png" alt="Logo"></p>

This is a simple console tool for changing all copyright labels of your source code.

## Supported Features:
 - [ ] Sign all not signed source files
 - [ ] Update copyright data for last owner
 - [ ] Automatically add new owner if the owner is changed 

 ## Support Files types
 * cpp
 * hpp
 * h
 * cc
 * qml
 * pro
 * txt
 * py


## Architecture:

<p align="center"> 
    <img src="./res/general application arhitecture.png">
</p>


 ## example

Sign not signed files.
``` bash
 cfixer -sourceDir /path/sources -sign /path/to/copyright/file
```

## Support options

| option  | arguments  |  description |
|---------|------------|--------------|
| sourceDir | pathToSourceDirectory  | This arrgument sets path to the source directory. By default it is sourceDir = **PWD**  | 
| sign  |  pathToFileWithSignPattern  |  This argument sets path to the sign pattern. This is a required argument  |


# This project supports next build targets:

|   Command or make target   |  Description    |
|------|------|
| **make test** | The run tests for a project (depending on Qt Tests, so you need to add Qt in Cmake using CMAKE_PREFIX_PATH) |
| **make doc** | The generate a documentation for a project (depending on doxygen) |
| **make deploy** | The generate distribution for a project (depending on CQtDeployer) |
| **make release** | The prepare Qt Installer framework repository for a project, generate a snap package and APK file for android (depending on CQtDeployer,  snapcraft, AndroidDeployer). |


---

<p align="center"> 
    <img src="./res/Credits.jpg">
</p>

Join the development fund and support QuasarApp to help with the development of our projects.

<a href="https://www.patreon.com/bePatron?u=9304737"><img src="https://img.shields.io/badge/ become a patron-red?&style=for-the-badge&logo=patreon&logoColor=white" height=30 width=180></a>



If you would like to use bitcoins to support us, you can transfer coins to theis address. If you want to be included in the patron list, send an e-mail message - QuasarApp@yandex.by.

**Note**: You must send a message signed with address of the bitcoin wallet from which the payment was made.

<p align="center"><img src="res/qr.png" alt="qrcode"></p>

<p align="center">bitcoin: bc1qzuymq7jc9q2x04wcwstr45tu8klm46zfl20wyp</p>

