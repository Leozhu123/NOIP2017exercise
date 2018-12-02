from cyaron import *

for i in range(1,100):
    print(i)
    input_io=IO()
    input_io.input_writeln(10)
    graph = Graph.tree(10,weight_limit=20)
    input_io.input_writeln(graph)
    m=randint(1,10)
    input_io.input_writeln(m)
    for j in range(1,m+1):
        input_io.input_write(randint(1,10))
    Compare.program("P1084.exe",input=input_io,std_program="std.exe")
