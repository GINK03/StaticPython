# encoding: utf-8

import re

""" メモ化の変数領域 """
class ___MEMRE:
  def __init__(self):
    self.mem = {}
__memre = ___MEMRE()

""" メモ化を実装した reの拡張版のmemre """
def search( regex, line ):
  if not __memre.mem.get( regex ):
    __memre.mem.setdefault( regex, re.compile(regex) )
  __m = __memre.mem2[line]
  return __m

''' here is test '''
'''
line = 'this test'
line2 = 'nemui pashi-----'
if search('(.*?)test', line):
  print search('(.*?)test', line).group(1)
  print _e[0]
if search('.*?(ui).*?(sh)', line2):
  print 'mome', _e[0], _e[1]
'''
