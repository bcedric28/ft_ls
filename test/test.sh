
i=1
y=0
ls > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
    echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi


TEST="-l"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-la"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi


TEST="-lar"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi


TEST="-lart"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-lartR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi


TEST="-lr"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-lrt"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-lrtR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-lt"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-ltR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-lR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-a"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-ar"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-art"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-artR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi


TEST="-at"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-atr"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-aR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi


TEST="-r"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-rt"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-rtR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-rR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-t"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-tR"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-R"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-y"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi

TEST="-a -a"
let "i++"
ls -1 $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ls.txt
./ft_ls $TEST ../../../ > /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt
DIFF=$(diff /Users/sstinglh/Desktop/test_result/${i}_ls.txt /Users/sstinglh/Desktop/test_result/${i}_ft_ls.txt)
if [ "$DIFF" != "" ]
then
    echo "TEST ${i} FAIL !"
echo "diff |$DIFF{}|"
else
    echo "TEST ${i} OK !"
fi
