# Scilab_API-Matrix-Multiplication
To build this code and load it to Scilab execute the following commands in scilab
files=["sci_foo.c"];
WITHOUT_AUTO_PUTLHSVAR = %t;
ilib_build('build_lib',['foo','sci_foo'],files,[]);
exec loader.sce

You can use the function "foo" for multiplication of two matrices.(After completing the above steps)
Example-
ans=foo([1,2],[1;2])
