#!/usr/bin/python

import lzma

l = lzma.LZMACompressor()
out1 = l.compress(open('raw.txt').read())
out2 = l.flush()
open('out.xz', 'wb+').write(out1 + out2)

