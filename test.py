import mre
import gen

line = 'here is a test document'

mre.search('[t|i](.*?)\s', line)
print mre._e
