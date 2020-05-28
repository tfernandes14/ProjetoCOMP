declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [2 x i8] c"\0A\00"
define i32 @method_a_int_int(i32 %.input) {
%input = alloca i32
store i32 %.input, i32* %input
%i = alloca i32
%.1 = add i32 0, 0
store i32 %.1, i32* %i
br label %while1
while1:
%.2 = load i32 , i32* %input
%.3 = add i32 0, 2
%.4 = add i32 %.2, %.3
store i32 %.4, i32* %input
%.5 = load i32 , i32* %i
%.6 = add i32 0, 1
%.7 = add i32 %.5, %.6
store i32 %.7, i32* %i
%.8 = load i32 , i32* %i
%.9 = add i32 0, 10
%.10 = icmp slt i32 %.8, %.9
br i1 %.10, label %while1, label %whileCont1
whileCont1:
%.11 = load i32 , i32* %input
ret i32 %.11
ret i32 0
}
define i32 @method_b_int_int(i32 %.input) {
%input = alloca i32
store i32 %.input, i32* %input
%k = alloca i32
%.1 = add i32 0, 0
store i32 %.1, i32* %k
br label %while2
while2:
%.2 = load i32 , i32* %input
%.3 = add i32 0, 3
%.4 = mul i32 %.2, %.3
store i32 %.4, i32* %input
%.5 = load i32 , i32* %k
%.6 = add i32 0, 1
%.7 = add i32 %.5, %.6
store i32 %.7, i32* %k
%.8 = load i32 , i32* %k
%.9 = add i32 0, 5
%.10 = icmp slt i32 %.8, %.9
br i1 %.10, label %while2, label %whileCont2
whileCont2:
%.11 = load i32 , i32* %input
ret i32 %.11
ret i32 0
}
define void @main(i32,i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%input = alloca i32
%aux = alloca i32
%aux1 = alloca i32
%.1 = add i32 0, 0
store i32 %.1, i32* %aux
%.2 = add i32 0, 0
store i32 %.2, i32* %aux1
%.3 = add i32 0, 0
%.4 = load i8**, i8*** %args
%.5 = add i32 1, %.3
%.6 = getelementptr i8*, i8** %.4, i32 %.5
%.7 = load i8*, i8** %.6
%.8 = call i32  @atoi(i8* %.7)
store i32 %.8, i32* %input
%.9 = load i32 , i32* %input
%.10 = add i32 0, 10
%.11 = icmp slt i32 %.9, %.10
br i1 %.11, label %then1, label %else1
then1:
%.12 = load i32 , i32* %input
%.13 = call i32 @method_a_int_int(i32 %.12)
store i32 %.13, i32* %aux
br label %ifCont1
else1:
%.14 = load i32 , i32* %input
%.15 = call i32 @method_b_int_int(i32 %.14)
store i32 %.15, i32* %aux1
br label %ifCont1
ifCont1:
%.16 = load i32 , i32* %aux
%.17 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.16)
%.18 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%.19 = load i32 , i32* %aux1
%.20 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.19)
ret void 
}
