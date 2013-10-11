# encoding: utf-8

import re

""" メモ化の変数領域 """
class ___MEMRE:
  def __init__(self):
    self.mem = {}
    self.mem2 = {}
__memre = ___MEMRE()

""" パールのレジスタもどきの実装 """
_e = None

""" メモ化を実装した reの拡張版のmemre """
def search( regex, line ):
  global _e
  """ メモリを溜めすぎた場合は破棄しなくはならない """
  if len( __memre.mem2.keys() ) > 100:
    __memre.mem2 = {} # dispiose memory 

  if not __memre.mem.get( regex ):
    __memre.mem.setdefault( regex, re.compile(regex) )
  if not __memre.mem2.get( line ):
    __memre.mem2.setdefault( line, __memre.mem[regex].search(line) )
  __m = __memre.mem2[line]
  _e  = __m.groups()
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
