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

namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {
namespace smart_enums {

""")

def WriteFooter(enum_dict, out, data):
  out.write('} // namespace smart_enums\n\n')
  out.write(data[0] + '\n')
  out.write(data[1])
  out.write("""
} // namespace enums
using namespace enums;
} // namespace oglwrap

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
  instances = ""
  suppress_unused = "// Just an ugly hack to surpress -Wunused-variable\ntemplate<typename T> static void _OGLWRAP_SUPPRESS_UNUSED() {\n"
  for gl_enum in sorted(enum_dict.keys()):
    ifdef = '#if OGLWRAP_DEFINE_EVERYTHING || defined(' + gl_enum + ')\n'
    out.write(ifdef)
    enum = CamelCase(gl_enum[3:])
    out.write('struct ' + enum + 'Enum {\n')
    for enum_class in enum_dict[gl_enum]:
      out.write('  operator ' + enum_class +
                '() const { return ' + enum_class + '(' + gl_enum + '); }\n')
    out.write('};\n')
    out.write('#endif\n\n')
    instances += ifdef + '  static smart_enums::' + enum + 'Enum k' + enum + ';\n#endif\n'
    suppress_unused += ifdef + '  (void) k' + CamelCase(gl_enum[3:]) + ';\n#endif\n'
  suppress_unused += '}\n'
  return [instances, suppress_unused]


# __main()__
#
file_list = [ f for f in listdir('../src') if isfile(join('../src', f)) ]
out = open('../../smart_enums.h', 'w')
WriteHeader(file_list, out)
enum_dict = {}
CreateEnumDictionary(enum_dict, file_list)
data = WriteEnums(enum_dict, out)
WriteFooter(enum_dict, out, data)
