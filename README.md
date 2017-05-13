# Scilab_API-Matrix-Multiplication<br />
To build this code and load it to Scilab execute the following commands in scilab<br />
Change the working directory of scilab to Scilab/share/scilab/contrib/toolbox_skeleton/sci_gateway.<br />

files=["sci_foo.c"];<br />
WITHOUT_AUTO_PUTLHSVAR = %t;<br />
ilib_build('build_lib',['foo','sci_foo'],files,[]);<br />
exec loader.sce<br />

You can use the function "foo" for multiplication of two matrices.(After completing the above steps)<br />
Example-<br />
ans=foo([1,2],[1;2])<br />
