declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [5 x i8] c"WOW\0A\00"
@.str.1 = constant [2 x i8] c"\0A\00"
@d_double = common global double 0.0
define double @method_test_double_double(double %.n) {
%n = alloca double
store double %.n, double* %n
%.1 = load double , double* %n
ret double %.1
ret double 0.0
}
define i32 @main(i32,i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.0, i32 0, i32 0))
%.2 = add i32 0, 4
%.3 = sitofp i32 %.2 to double
%.4 = call double @method_test_double_double(double %.3)
%.5 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.4)
%.6 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.1, i32 0, i32 0))
%.7 = add i32 0, 2
%.8 = sitofp i32 %.7 to double
store double %.8, double* @d_double
%.9 = load double , double* @d_double
%.10 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.9)
ret i32 0
}