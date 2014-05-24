#!/usr/bin/python

from os import listdir
from os.path import isfile, join

def CamelCase(str):
  return str.replace('_', ' ').title().replace(' ', '')

def WriteHeader(file_list, out):
  guard = 'OGLWRAP_SMART_ENUMS_H_'
  out.write('// Copyright (c) 2014, Tamas Csala\n\n')
  out.write('#ifndef ' + guard + '\n')
  out.write('#define ' + guard + '\n')
  out.write('\n#include "./config.h"\n')
  for file_name in file_list:
    if file_name.endswith('.txt'):
      path = './enums/' +  file_name.replace('.txt', '.h')
      out.write('#include "' + path + '"\n')
  out.write("""#include "./define_internal_macros.h"

namespace oglwrap {

class SmartEnums {
public:

""")

def WriteFooter(enum_dict, out):
  out.write('\n};\n\n')
  out.write('#if OGLWRAP_INSTANTIATE\n')
  for gl_enum in enum_dict:
    out.write('#if OGLWRAP_DEFINE_EVERYTHING || defined(' + gl_enum + ')\n')
    enum = CamelCase(gl_enum[3:])
    out.write('  SmartEnums::' + enum + 'Enum SmartEnums::' + enum + ';\n')
    out.write('#endif\n')
  out.write('#endif\n\n')
  out.write("""} // oglwrap


#include "./undefine_internal_macros.h"

#endif
""")

def CreateEnumDictionary(enum_dict, file_list):
  for file_name in file_list:
    if file_name.endswith('.txt') and not file_name.endswith('_binding.txt'):
      enum_class_name = CamelCase(file_name[:-4])

      for line in open('../src/' + file_name):
        enum = line[:-1]
        if enum in enum_dict:
          enum_dict[enum].append(enum_class_name)
        else:
          enum_dict[enum] = [enum_class_name]

def WriteEnums(enum_dict, out):
  for gl_enum in sorted(enum_dict.keys()):
    out.write('#if OGLWRAP_DEFINE_EVERYTHING || defined(' + gl_enum + ')\n')
    enum = CamelCase(gl_enum[3:])
    out.write('  struct ' + enum + 'Enum {\n')
    for enum_class in enum_dict[gl_enum]:
      out.write('    constexpr operator ' + enum_class + '() const { return ' + enum_class + '(' + gl_enum + '); }\n')
    out.write('  };\n')
    out.write('  static ' + enum + 'Enum ' + enum + ';\n')
    out.write('#endif\n\n')

# __main()__
#
file_list = [ f for f in listdir('../src') if isfile(join('../src', f)) ]
out = open('../../smart_enums.h', 'w')
WriteHeader(file_list, out)
enum_dict = {}
CreateEnumDictionary(enum_dict, file_list)
WriteEnums(enum_dict, out)
WriteFooter(enum_dict, out)
