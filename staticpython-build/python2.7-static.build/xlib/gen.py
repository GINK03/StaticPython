# coding:utf-8
# GENERIC SEIALIZE LIB
# 型付きのシリアライズとデシリアライズを行うものである

import cPickle
import base64

dumps = lambda x : base64.encodestring(cPickle.dumps(x)).replace('\n','')
loads = lambda x : cPickle.loads(base64.decodestring(x))


'''
# データをシリアライズして、型情報が欠損しないことを確認
class Data:
  def __init__(self):
    self.a = 'hoge'
d = Data()
d1 = dumps(d)
print d1
d2 = loads(d1)
print d2
print d2.a
print isinstance(d2,Data)
'''
