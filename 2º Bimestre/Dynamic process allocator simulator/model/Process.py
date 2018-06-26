#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# Process class here

class Process:
    process_List = []
    process_Num = 0
    process_PID = 1

    def __init__(self, process_Name, process_Size):
        self.process_Name = process_Name
        self.process_Size = process_Size
        self.process_PID = Process.process_PID
        self.process_Memories = {
            'First Fit'   : 0,
            'Best Fit'    : 0,
            'Worst Fit'   : 0,
            'Circular Fit': 0,
        }
        Process.process_PID += 1
        Process.process_Num += 1

        self.__class__.process_List.append(self)

    def memoryAssociated(self):
        inMemory = {}
        for key, value in self.process_Memories.items():
            if value:
                inMemory.update({key: value})

        return inMemory

    def __str__(self):
        return "PID: %s - Process: \"%s\" - Size %sKB" % (self.process_PID,
                                                          self.process_Name,
                                                          self.process_Size,
                                                          )
