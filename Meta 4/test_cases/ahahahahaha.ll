declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.true = constant [5 x i8] c"true\00"
@.false = constant [6 x i8] c"false\00"
@.int = constant [3 x i8] c"%d\00"
@.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [3 x i8] c\0A\00"
@.str.1 = constant [3 x i8] c\0A\00"
@.str.2 = constant [3 x i8] c\0A\00"
define i1 @bool() {
%i = alloca i1
%.1 = or i1 false, true
store i1 %.1, i1* %i
%.2 = load i1, i1* %i
br i1 %.2, label %then0, label %else0
then0:
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([5 x i8], [5 x i8]* @.str.true, i32 0, i32 0))
br label %ifCont0
else0:
%.4 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.false, i32 0, i32 0))
br label %ifCont0
ifCont0:
%.4 = call i32 (i8*, ...)@printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.0, i32 0, i32 0))
%.5 = load i1 , i1* %i
ret i1 0
}
define i32 @integer() {
%i = alloca i32
%.1 = add i32 0, 1
store i32 %.1, i32* %i
%.2 = load i32, i32* %i
%.3 = call i32 (i8*, ...) @printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.int, i32 0, i32 0), i32 %.2)
%.4 = call i32 (i8*, ...)@printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.1, i32 0, i32 0))
%.5 = load i32 , i32* %i
ret i32 %.5
ret i32 0
}
define double @real() {
%i = alloca double
store double %.0, double* %i
%.1 = load double, double* %i
%.2 = call i32 (i8*, ...) @printf(i8* getelementptr ([6 x i8], [6 x i8]* @.str.double, i32 0, i32 0), double %.1)
%.3 = call i32 (i8*, ...)@printf(i8* getelementptr ([3 x i8], [3 x i8]* @.str.2, i32 0, i32 0))
%.4 = load double , double* %i
ret double %.4
ret double 0
}
define void @main_string(i32,i8** %.args) {
%.1 = call boolean @bool()
%.2 = call int @integer()
%.3 = call double @real()
ret void 
}
