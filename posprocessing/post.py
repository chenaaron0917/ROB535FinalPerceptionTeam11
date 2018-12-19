

a = open("Task1_team11_currentbest.csv","r")
predict = a.readlines()
print len(predict)
count = 0
for n in range(2):
	print n
	for i in range(2,len(predict)-1):
		# print predict[i]
		text = predict[i].split(',')
		folder = text[0].split('/')[0]
		file = text[0].split('/')[1]
		cl = int(float(text[1].split('\n')[0]))
		text_last = predict[i-1].split(',')
		folder_last = text_last[0].split('/')[0]
		cl_last = int(float(text_last[1].split('\n')[0]))
		text_next = predict[i+1].split(',')
		folder_next = text_next[0].split('/')[0]
		cl_next = int(float(text_next[1].split('\n')[0]))
		# print type(cl),cl

		# if folder_last == folder_next and cl_last == cl_next and cl_last != 0 and cl == 0 and cl != cl_last:
		if folder_last == folder_next and cl_last == cl_next and cl_last != 0 and cl != cl_last:
			print predict[i]
			add = folder+"/"+file+","+str(cl_next)+"\n"
			predict[i] = add
			count +=1
			# break

a.close()
f = open("test.csv","w")
f.writelines(predict)
f.close()
print count