#!/usr/bin/env python

from cyaron import * # ����CYaRon�Ŀ�

for i in range(6, 11): # ����[1, 4)��Χ��ѭ����Ҳ���Ǵ�1��3
    test_data = IO(file_prefix="sleep", data_id=i) # ���� heat[1|2|3].in/out �����������

    n=randint(3,1000000000)
    k=randint(1,n/2)
    test_data.input_writeln(n) # д�뵽�����ļ���Զ��Կո�ָ����
    test_data.output_gen("sleep.exe") 
