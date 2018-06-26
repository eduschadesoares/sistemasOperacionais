#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from random import randint


# Memory class here

class Memory:
    memory_List = []

    def __init__(self, memory_Id, memory_Size):
        self.memory_Id = memory_Id
        self.memory_Size = memory_Size
        self.memory_Available = 0
        self.memory_MaxForProcess = 0
        self.memory_LastPosition = 0
        self.memory_Data = []

        self.memory_ProcessQuantity = []

        # Creates an array with 0
        for i in range(self.memory_Size):
            # Some tests
            # n = randint(0, 1)
            n = 0
            self.memory_Data.append(n)

        # Add this object to the list
        self.__class__.memory_List.append(self)

    def __str__(self):
        # Returns size and names of each memory
        fitType = self.memoryName()
        return " %s - Size: %s KB - Available: %s KB - Max size for process: %s KB Process quantity: %s" % (fitType,
                                                                                                            self.memory_Size,
                                                                                                            self.memory_Available,
                                                                                                            self.memory_MaxForProcess,
                                                                                                            self.memory_ProcessQuantity,
                                                                                                            )

    def memoryName(self):
        if self.memory_Id == 0:
            fitType = 'First Fit'
        elif self.memory_Id == 1:
            fitType = 'Best Fit'
        elif self.memory_Id == 2:
            fitType = 'Worst Fit'
        elif self.memory_Id == 3:
            fitType = 'Circular Fit'
        return fitType

    def createMemories(self, size):
        for i in range(4):
            mem = Memory(i, size)
            mem.verifyAvailableSpace()

    def verifyAvailableSpace(self):
        counter = 0
        self.memory_MaxForProcess = 0
        self.memory_Available = 0

        # Verify memory size
        for i in range(self.memory_Size):
            if self.memory_Data[i] is 0:
                self.memory_Available += 1

        # Verify max size for a process
        for i in range(self.memory_Size):
            if self.memory_Data[i] is 0:
                counter += 1
                if counter > self.memory_MaxForProcess:
                    self.memory_MaxForProcess = counter
            else:
                counter = 0

    def removeProcessFromMemory(self, pid):
        for i in range(self.memory_Size):
            if self.memory_Data[i] is pid:
                self.memory_Data[i] = 0

        self.memory_ProcessQuantity.remove(pid)
        self.verifyAvailableSpace()

    def firstFit(self, size, pid):
        counter, final, initial = 0, 0, 0
        try:
            for i in range(self.memory_Size):
                if self.memory_Data[i] is 0:
                    if counter is 0:
                        initial = i
                    counter += 1
                else:
                    initial = 0
                    counter = 0
                if counter is size:
                    final = i
                    break

            for i in range(initial, final + 1):
                self.memory_Data[i] = pid

        except Exception as error:
            print(error)

        self.memory_ProcessQuantity.append(pid)
        self.verifyAvailableSpace()

        content = {
            'fit': 'First Fit',
            'position': initial + 1
        }

        return content

    def bestFit(self, size, pid):
        initial, final = 0, 0
        flagFinal, flagInitial, sizeCounter = 0, 0, 0
        lastPosition = False
        shortestCounter = self.memory_MaxForProcess + 1

        try:
            for i in range(self.memory_Size):
                if i is self.memory_Size - 1 and self.memory_Data[i] is 0:
                    if self.memory_Data[i - 1] is not 0:
                        flagInitial = i
                    lastPosition = True
                    sizeCounter += 1
                    flagFinal = i

                if self.memory_Data[i] is 0 and lastPosition is False:
                    if sizeCounter is 0:
                        flagInitial = i
                    sizeCounter += 1
                    flagFinal = i

                else:
                    if sizeCounter > size:
                        if sizeCounter < shortestCounter:
                            shortestCounter = sizeCounter
                            initial = flagInitial
                            final = flagFinal

                    # Verify size
                    if sizeCounter is size:
                        shortestCounter = sizeCounter
                        initial = flagInitial
                        final = flagFinal
                        break

                    sizeCounter = 0

            if shortestCounter > size:
                final = initial + (size - 1)

            for i in range(initial, final + 1):
                self.memory_Data[i] = pid

        except Exception as error:
            print(error)

        self.memory_ProcessQuantity.append(pid)
        self.verifyAvailableSpace()

        content = {
            'fit': 'Best Fit',
            'position': initial + 1
        }

        return content

    def worstFit(self, size, pid):
        # Same of best fit
        initial, final = 0, 0
        flagFinal, flagInitial, sizeCounter = 0, 0, 0
        lastPosition = False
        shortestCounter = self.memory_MaxForProcess + 1

        try:
            for i in range(self.memory_Size):
                if i is self.memory_Size - 1 and self.memory_Data[i] is 0:
                    if self.memory_Data[i - 1] is not 0:
                        flagInitial = i
                    lastPosition = True
                    sizeCounter += 1
                    flagFinal = i

                if self.memory_Data[i] is 0 and lastPosition is False:
                    if sizeCounter is 0:
                        flagInitial = i
                    sizeCounter += 1
                    flagFinal = i

                else:
                    if sizeCounter > size:
                        # Changed sign - less to more
                        if sizeCounter > shortestCounter:
                            shortestCounter = sizeCounter
                            initial = flagInitial
                            final = flagFinal

                    # Verify size
                    # Changed validation from "is size" to is "shortestCounter"
                    if sizeCounter is shortestCounter - 1:
                        shortestCounter = sizeCounter
                        initial = flagInitial
                        final = flagFinal
                        break

                    sizeCounter = 0

            if shortestCounter > size:
                final = initial + (size - 1)

            for i in range(initial, final + 1):
                self.memory_Data[i] = pid

        except Exception as error:
            print(error)

        self.memory_ProcessQuantity.append(pid)
        self.verifyAvailableSpace()

        content = {
            'fit': 'Worst Fit',
            'position': initial + 1
        }

        return content

    def circularFit(self, size, pid):
        counter, final, initial = 0, 0, 0
        i = 0
        try:
            while i < self.memory_Size:
                if self.memory_LastPosition is self.memory_Size:
                    self.memory_LastPosition = 0
                if self.memory_Data[self.memory_LastPosition] is 0:
                    if counter is 0:
                        initial = self.memory_LastPosition
                    counter += 1
                else:
                    initial = 0
                    counter = 0
                if counter is size:
                    final = self.memory_LastPosition
                    break
                if self.memory_LastPosition is self.memory_Size - 1:
                    counter = 0
                    self.memory_LastPosition = 0
                    initial = 0
                else:
                    self.memory_LastPosition += 1
                i += 1
            for i in range(initial, final + 1):
                self.memory_Data[i] = pid

        except Exception as error:
            print(error)

        self.memory_LastPosition += 1

        self.memory_ProcessQuantity.append(pid)
        self.verifyAvailableSpace()

        content = {
            'fit': 'Circular Fit',
            'position': initial + 1
        }

        return content
