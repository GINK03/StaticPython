# encoding: utf-8
import sys
import test
## pythonのバージョンによってはreloadが可能である
#  reload(sys)
#  sys.setdefaultencoding('utf-8')

import cPickle as pickle
import gext
class HAGE:
  def __init__(self, a):
    self.a = a
    self.l = [a]
    self.d = {a:a}

class MOGE:
  def __init__(self, a):
    self.a = a
    self.l = [a]
    self.d = {a:a}

if __name__ == '__main__':
  for i in range(1,2):
    if i%2 == 0:
      m = MOGE(i)
    else:
      m = HAGE(i)
      m = test.MAGE(i)
    raw = gext.msgcnv(pickle.dumps(m))
    #print type(raw)
    hdpmap = '\t'.join(['somekey', raw])
    rawcon = hdpmap.split('\t')[-1]
    print rawcon
    mg = pickle.loads(gext.msgrcv(rawcon))
    if i%2 == 0:
      print isinstance(mg, MOGE) 
    else:
      print isinstance(mg, HAGE)
    #print mg.a, mg.l, mg.d
    #rawcon.replace(unichr(219), '\n')
