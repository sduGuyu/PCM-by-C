# PCM-by-C
A homework of course Communication Theory which required us to implement PCM by C. 

一、基本原理
1.[0, 1]内均匀分为8段，段内16级的均匀量化
2.每个抽样点进行8位折叠二进制编码（极性码、段落码、段内码）

二、编程思路
1.先根据正负确定极性码
2.转化为绝对值与段落码的端点进行比较得到段落与段落码
3.根据段落确定量化间隔，并且得到相对偏差，循环比较得到段内码
