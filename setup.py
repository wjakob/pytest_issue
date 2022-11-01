from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="inheritance_issue",
            sources=["inheritance_issue.c"],
        ),
    ]
)
