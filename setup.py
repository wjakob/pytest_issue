from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="pytest_issue",
            sources=["pytest_issue.c"],
        ),
    ]
)
