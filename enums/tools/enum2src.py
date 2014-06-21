#!/usr/bin/python

from os import listdir
from os.path import isfile, join

file_list = [ f for f in listdir('..') if isfile(join('..', f)) ]

for file_name in file_list:
  if file_name.endswith('.h'):
    out = open('../src/' + file_name[:-2] + '.txt', 'w')
    for line in open('../' + file_name):
      if line.find('GetBindingTarget') != -1:
        break

      def_str = 'defined(GL_'
      start_pos = line.find(def_str)
      if start_pos != -1:
        end_pos = line.find(')')
        enum = line[start_pos + len(def_str)-3 : end_pos]
        out.write(enum + '\n')
    out.close()
    
