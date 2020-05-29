declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [2 x i8] c"\0A\00"
@.str.1 = constant [2 x i8] c"\0A\00"
@.str.2 = constant [2 x i8] c"\0A\00"
@.str.3 = constant [10 x i8] c"%%%%%%%%\0A\00"
define void @main(i32,i8** %.args) {
%args = alloca i8**
store i8** %.args, i8*** %args
%.1 = fadd double 0.000000, 0.0000000000000000e+00
%.2 = fsub double 0.0, %.1
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.2)
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.0, i32 0, i32 0))
%.5 = add i32 0, 0
%.6 = sub i32 0, %.5
%.7 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.6)
%.8 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.1, i32 0, i32 0))
%.9 = fadd double 0.000000, 0.0000000000000000e+00
%.10 = fsub double 0.0, %.9
%.11 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.10)
%.12 = call i32 (i8*, ...) @printf(i8* getelementptr ([2 x i8], [2 x i8]* @.str.2, i32 0, i32 0))
%.13 = call i32 (i8*, ...) @printf(i8* getelementptr ([10 x i8], [10 x i8]* @.str.3, i32 0, i32 0))
ret void
}
