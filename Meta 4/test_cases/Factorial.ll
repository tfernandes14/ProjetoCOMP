declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
define i32 @method_factorial_int_int(i32 %.n) {
%n = alloca i32
store i32 %.n, i32* %n
%.1 = load i32 , i32* %n
%.2 = add i32 0, 0
%.3 = icmp eq i32 %.1, %.2
br i1 %.3, label %then1, label %else1
then1:
%.4 = add i32 0, 1
ret i32 %.4
br label %ifCont1
else1:
br label %ifCont1
ifCont1:
%.5 = load i32 , i32* %n
%.6 = load i32 , i32* %n
%.7 = add i32 0, 1
%.8 = sub i32 %.6, %.7
%.9 = call i32 @method_factorial_int_int(i32 %.8)
%.10 = mul i32 %.5, %.9
ret i32 %.10
ret i32 0
}
define void @main(i32,i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%argument = alloca i32
%.1 = add i32 0, 0
%.2 = load i8**, i8*** %args
%.3 = add i32 1, %.1
%.4 = getelementptr i8*, i8** %.2, i32 %.3
%.5 = load i8*, i8** %.4
%.6 = call i32  @atoi(i8* %.5)
store i32 %.6, i32* %argument
%.7 = load i32 , i32* %argument
%.8 = call i32 @method_factorial_int_int(i32 %.7)
%.9 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.8)
ret void 
}
