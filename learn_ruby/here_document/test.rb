#!/usr/bin/ruby -w
# -*- coding:UTF-8 -*-



print <<EOF

	这是第一种创建here document
	多行字符串，注意<<终止符 没有空格
EOF

print <<"EOF"            #与上面的相同

	这是第二种创建here document的方法
	多行字符串

EOF

print <<`EOC`    #执行命令
	echo hi there
	echo lo there

EOC

