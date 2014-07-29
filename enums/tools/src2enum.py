#!/usr/bin/python

from os import listdir
from os.path import isfile, join

def CamelCase(str):
  return str.replace('_', ' ').title().replace(' ', '')

def WriteEnum(file_name, file_base_name, out, is_binding):
  guard = 'OGLWRAP_ENUMS_' + file_base_name.upper() + '_H_'
  out.write('// Copyright (c) 2014, Tamas Csala\n\n')
  out.write('#ifndef ' + guard + '\n')
  out.write('#define ' + guard + '\n')
  out.write('\n#include "../config.h"\n')
  if is_binding:
    out.write('#include "../debug/debug_output.h"\n')
    out.write('#include "./' + file_name.replace('binding.txt', 'type.h') + '"\n')
  out.write("""
namespace OGLWRAP_NAMESPACE_NAME {
namespace enums {

enum class """)
  out.write(CamelCase(file_base_name) + ' : GLenum {\n')

  for line in open('../src/' + file_name):
    enum = line[:-1]
    out.write('#if OGLWRAP_DEFINE_EVERYTHING || defined(' + enum + ')\n')
    out.write('  k' + CamelCase(enum[3:]) + ' = ' + enum + ',\n')
    out.write('#endif\n')

  out.write("""};

}  // namespace enums
using namespace enums;
""")

def HandleNormalEnumFile(file_name, file_base_name, out):
  WriteEnum(file_name, file_base_name, out, False)

def HandleBindingEnumFile(file_name, file_base_name, out):
  WriteEnum(file_name, file_base_name, out, True)
  binding = CamelCase(file_base_name)
  target = binding.replace('Binding', 'Type')
  out.write('inline ' + binding + ' GetBindingTarget(' +
             target + ' type) {\n')
  out.write('  ' + binding + ' target;\n\n')
  out.write('  switch (type) {\n')

  binding_lines = open('../src/' + file_name).readlines()
  target_lines = open('../src/' + file_name.replace('binding', 'type')).readlines()
  if len(binding_lines) != len(target_lines):
    raise Exception(file_name + ' mismatches ' +
      file_name.replace('binding', 'type') + ' in element size.')
  for line_num in xrange(0, len(binding_lines)):
    binding_enum = binding_lines[line_num][:-1]
    target_enum = target_lines[line_num][:-1]
    out.write('#if OGLWRAP_DEFINE_EVERYTHING || defined(' + binding_enum +
              ') && defined(' + target_enum + ')\n')
    out.write('    case ' + target + '::k' + CamelCase(target_enum[3:]) + ':\n')
    out.write('      target = ' + binding + '::k' + CamelCase(binding_enum[3:]) + ';\n')
    out.write('      DebugOutput::LastUsedBindTarget() = "' + binding_enum + '";\n')
    out.write('      break;\n')
    out.write('#endif\n')
  out.write('  }\n\n return target;\n}\n\n')

def EndFile(out):
  out.write("""}  // namespace oglwrap

#endif
""")
  out.close()


file_list = [ f for f in listdir('../src') if isfile(join('../src', f)) ]

for file_name in file_list:
  file_base_name = file_name[:-4]
  out = open('../' + file_base_name + '.h', 'w')

  if file_name.endswith('_binding.txt'):
    HandleBindingEnumFile(file_name, file_base_name, out)
  elif file_name.endswith('.txt'):
      HandleNormalEnumFile(file_name, file_base_name, out)

  EndFile(out)
