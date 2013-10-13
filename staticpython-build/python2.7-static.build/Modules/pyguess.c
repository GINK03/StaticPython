/*
 * Copyright (c) 2012 Tsukasa Hamano <code@cuspy.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <Python.h>

/** linkerに実装のリンクは任せる */
//#include "./guess.c"
//#include "./guess_tab.c"


const char *guess_jp(const char *buf, int buflen);

static char pyguess_doc[] =
    "Gauche's charactor encoding detector for Python\n";

static PyObject * pyguess_guess(PyObject *self, PyObject *args)
{
    PyObject *ret;
    char *str;
    int len;
    if(!PyArg_ParseTuple(args, "s#", &str, &len)){
        return NULL;
    }
    ret = PyString_FromString(guess_jp(str, len));
    return ret;
}

static PyMethodDef methods[] = {
	{"guess", pyguess_guess, METH_VARARGS, "guess.\n"},
	{NULL, NULL}
};

void initpyguess(void){}
void initguess_tab(void){}
void initguess(void)
{
	Py_InitModule3("guess", methods, pyguess_doc);
}