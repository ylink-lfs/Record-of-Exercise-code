# -*- coding:utf-8 -*-

def insert(original, new, pos):
    return original[:pos] + new + original[pos:]

class BinDecimal:
    def printBin(self, num):
        if num == 0:
            return '0'
        elif num == 1:
            return '1'
        i = 0
        decimal_str = ''
        while i < 32 and num != 1:
            num *= 2
            decimal_str += '1' if num >= 1 else '0'
            if num == 1:
                break
            elif num > 1:
                num -= 1
            i += 1
            
        if i == 32:
            return "Error"
        else:
            return '0.' + decimal_str
