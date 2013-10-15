import mre
import gen
mre.PERL_COMPAT = True
line = 'here is a test document'

class MAGE:
  def __init__(self, a):
    self.a = a
    self.l = [a]
    self.d = {a:a}

mre.search('[t|i](.*?)\s', line)

print mre._
