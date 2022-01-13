import gdb
class V (gdb.Command):
  """Greet the whole world."""

  def __init__ (self):
    super (V, self).__init__ ("v", gdb.COMMAND_USER)

  def invoke (self, arg, from_tty):
    arg = arg.replace("[", ".ptr[")
    print(gdb.parse_and_eval(arg))

V ()

