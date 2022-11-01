#include <Python.h>

static PyModuleDef my_module = {
    PyModuleDef_HEAD_INIT,
    .m_name = "inheritance_issue",
    .m_doc = "Reproducer for an issue involving type inheritance",
    .m_size = -1,
};

static PyType_Slot my_property_slots[] = {
    { Py_tp_base, NULL },
#if FIX_ISSUE
    { Py_tp_methods, NULL },
    { Py_tp_members, NULL },
#endif
    { 0, NULL }
};

static PyType_Spec my_property_spec = {
    .name = "inheritance_issue.my_property",
    .flags = Py_TPFLAGS_DEFAULT,
    .slots = my_property_slots
};

PyMODINIT_FUNC
PyInit_inheritance_issue(void)
{
    PyObject *m = PyModule_Create(&my_module);
    if (m == NULL)
        return NULL;

    my_property_slots[0].pfunc = &PyProperty_Type;
#if FIX_ISSUE
    my_property_slots[1].pfunc = PyType_GetSlot(&PyProperty_Type, Py_tp_methods);
    my_property_slots[2].pfunc = PyType_GetSlot(&PyProperty_Type, Py_tp_members);
#endif

    PyObject *my_property = PyType_FromSpec(&my_property_spec);

    if (PyModule_AddObject(m, "my_property", my_property) < 0) {
        Py_DECREF(my_property);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}
