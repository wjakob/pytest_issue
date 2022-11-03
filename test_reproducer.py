from pytest_issue import foo
import pytest

@pytest.mark.parametrize('a', range(1000))
def test01_stderr(capfd, a):
    with pytest.raises(RuntimeError, match='An exception occurred!'):
        foo()
    captured = capfd.readouterr()
    assert captured.err.strip() == "Hello world!"
