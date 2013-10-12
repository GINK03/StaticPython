#include <Python.h>
#include <string.h>
/**　二乗するだけのサンプル関数 */
static PyObject*
gext_info(PyObject* self, PyObject* args)
{
  int n;
  if(!PyArg_ParseTuple(args, "i", &n))
    return NULL;
  //printf("soul of control");
  return Py_BuildValue("i", n * n);
}

/** 前の状態から変化したらtrueを返する
 *  hadoopのreduceの時に使うなどが考えられる */
static PyObject*
gext_keyregister(PyObject* self, PyObject* args)
{
  static char* ss = NULL;
  char* s;
  if(!PyArg_ParseTuple(args, "s", &s))
    return Py_BuildValue("s", NULL);

  if( ss == NULL ){
    ss = s;
    return Py_BuildValue("s", NULL);
  }
  // 一致時にnullを返す
  if( strcmp(s, ss) == 0 ){
    return Py_BuildValue("s", NULL);
  } else {
  // 不一致にstring objectを返却して処理を通す
  // static memoryの内容を更新する
    ss = s;
    return Py_BuildValue("s", s);
  }
  return Py_BuildValue("s", NULL);
}

/** 独自にチューニングされたsplit関数
 *  ポインタとアドレス操作で死ぬかもしれない */
static PyObject*
gext_firesplit(PyObject* self, PyObject* args)
{
  char* s = NULL;
  if(!PyArg_ParseTuple(args, "s", &s) || s == NULL)
    return Py_BuildValue("[]");

  int LEN = 10000;
  char* delim = ",      ";
  char* parselist[LEN]; int cnt = 0;
  char* tk = strtok(s, delim);
  while( tk != NULL ) {
    parselist[cnt++] = tk;
    tk = strtok(NULL, delim);
  }
  /** formatがよろしくやってくれない？ので大変であるが組み立てる */
  char format[1024 * 10]; memset(format, '\0', sizeof(char) * 1024 * 10);
  int cur = 0;
  int i;
  for(i = 0; i < cnt; i++){ 
    if(i == 0){ format[0] = '[';};
    format[++cur] = 's'; format[++cur] = ',';
  } 
  format[cur] = ']'; // ,をオーバーロード
  //printf(format); printf("\n"); // デバッグライン
  return Py_VaBuildValue(format, parselist);
}

static PyMethodDef methods[] = {
  {"info", (PyCFunction)gext_info, METH_VARARGS, "return factorial.\n"},
  {"kreg", (PyCFunction)gext_keyregister, METH_VARARGS, "return string object.\n"},
  {"split", (PyCFunction)gext_firesplit, METH_VARARGS, "return list of string.\n"},
  {NULL, NULL, 0, NULL}
};

static char* gext_doc = "soul of control";
void initgext(void)
{
  Py_InitModule3("gext", methods, gext_doc);
}
