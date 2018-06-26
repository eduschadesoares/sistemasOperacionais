#!/usr/bin/env python3
# -*- coding: utf-8 -*-

#Starting stuff here

import sys
sys.path.append('..')

from controller.TerminalController import CtrlMemory


#Initialization of terminal controller
if __name__ == '__main__':
    try:
        main = CtrlMemory()
        main.startMemory()
        main.insertPrograms()
    except Exception as error:
        print("Something went wrong!")
        print(error)
else:
    print("Program is being executed by module")
    print("Try again please: \"python start.py\"")