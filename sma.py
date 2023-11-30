import ctypes

lib = ctypes.CDLL("./sma.so")
sma = lib.sma
sma.argtypes = [ctypes.c_ulonglong, ctypes.c_ulonglong, ctypes.c_ulonglong]
sma.restype = ctypes.c_ulonglong

if __name__ == "__main__":
    # Use test function
    from utils import test_function

    test_function(sma)
