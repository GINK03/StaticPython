# encoding: utf-8

import re

""" メモ化の変数領域 """
class ___MEMRE:
  def __init__(self):
    self.mem = {}
    self.mem_regexline = {}
__memre = ___MEMRE()

"""PERL COMPAT INTERFACE"""
PERL_COMPAT = False
_ = None

""" メモ化を実装した reの拡張版のmemre """
def search( regex, line ):
  if not __memre.mem.get( regex ):
    __memre.mem.setdefault( regex, re.compile(regex) )
  
  __key = unichr(219).join([regex, line])
  if not __memre.mem_regexline.get( __key ):
    __memre.mem_regexline.setdefault( __key, __memre.mem[regex].search(line) )
  __m = __memre.mem_regexline[__key]
  
  """ If perl compat is on """
  global PERL_COMPAT
  global _
  if PERL_COMPAT and __m:
    _ = __m.groups()
  
  return __m

def sub( regex, tgt, line ):
  if not __memre.mem.get( regex ):
    __memre.mem.setdefault( regex, re.compile(regex) )
  
  __key = unichr(219).join([regex, tgt, line])
  if not __memre.mem_regexline.get( __key ):
    __memre.mem_regexline.setdefault( __key, __memre.mem[regex].sub( tgt , line ) )
  return  __memre.mem_regexline[__key]

''' here is test '''
if __name__ == '__main__':
  PERL_COMPAT = True
  line = 'this test'
  line2 = 'nemui pashi-----'
  if search('(.*?)test', line):
    print search('(.*?)test', line).group(1)
    print _[0]
  if search('.*?(ui).*?(sh)', line2):
    print 'mome', _[0], _[1]

  line = 'hagehagepandahageta'
  print sub('h.*?e', 'moge', line)
