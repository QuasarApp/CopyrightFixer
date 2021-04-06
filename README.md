# Copyright Fixer

This is simple console tool for change all copyrigh labels of your source code.

## Support Features:
 - [ ] Sign all not signed source files.
 - [ ] Update copyright data for last owner
 - [ ] Automaticly add new owner if the owner is changed 

 ## Support Files types
 * cpp
 * hpp
 * h
 * cc
 * qml
 * pro
 * txt
 * py


 ## exemple

Sign not signed files.
``` bash
 cfixer -sourceDir /path/sources -sign /path/to/copyright/file -currentOwner QuasraApp 
```

## Support options

| option  | arguments  |  discription |
|---------|------------|--------------|
| sourceDir | pathToSourceDirectory  | This arrgument sets path to the source directory. By default it is sourceDir = **PWD**  | 
| sign  |  pathToFileWithSignPatern  |  This argument sets path to the sign patern. This is a required argument  | 
| currentOwner | ownerName |  This argument sets name of the current owner of the code. | 


# This project supports next build targets:

|   Command or make target   |  Description    |
|------|------|
| **make test** | The run tests for a project (dependet of Qt Tests, so you need to add Qt in Cmake using CMAKE_PREFIX_PATH) |
| **make doc** | The generate a documentation for a project (dependet of doxygen) |
| **make deploy** | The generate distribution for a project (dependet of CQtDeployer) |
| **make release** | The prepare Qt Installer framework repository for a project, generate a snap package and APK file for android (dependet of CQtDeployer,  snapcraft, AndroidDeployer). |

---

<span style="text-align: center"> 

## ![Credits](./res/Credits.jpg)

 </span>

Join the development fund and support QuasarApp to help with the development of our projects.

<a href="https://www.patreon.com/bePatron?u=9304737"><img src="https://img.shields.io/badge/ become a patron-red?&style=for-the-badge&logo=patreon&logoColor=white" height=30 width=180></a>



If you would like to use bitcoins to support us, you can transfer coins to these address. If you want to be included in the patron list, send an e-mail message - QuasarApp@yandex.by.

**Note**: You must send a message signed with address of the bitcoin wallet from which the payment was made.

![support](https://user-images.githubusercontent.com/12465465/101282118-25222d00-37e4-11eb-9ffb-4ebd6a3a0bc7.png)

bitcoin:bc1q4wnp58plhx4fwnfnzz3e4slulv2gzzts89w2f7