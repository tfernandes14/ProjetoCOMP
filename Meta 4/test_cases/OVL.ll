declare i32 @printf(i8*, ...)
declare i32 @atoi(i8*)
@.str.true = constant [5 x i8] c"true\00"
@.str.false = constant [6 x i8] c"false\00"
@.str.int = constant [3 x i8] c"%d\00"
@.str.double = constant [6 x i8] c"%.16e\00"
@.str.0 = constant [19 x i8] c"I have a parameter\00"
@.str.1 = constant [25 x i8] c"I don't have a parameter\00"
@overload_int = common global i32 0
define void @method_overload_void_int(i32 %.n) {
%n = alloca i32
store i32 %.n, i32* %n
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr ([19 x i8], [19 x i8]* @.str.0, i32 0, i32 0))
ret void 
}
define void @method_overload_void() {
%.1 = call i32 (i8*, ...) @printf(i8* getelementptr ([25 x i8], [25 x i8]* @.str.1, i32 0, i32 0))
ret void 
}
define i32 @main(i32 %.n) {
%n = alloca i32
store i32 %.n, i32* %n
call void @method_overload_void()
ret i32 0
}
