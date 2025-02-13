from setuptools import setup, find_packages

setup(
    name="endecrypter",
    version="1.11.2",
    packages=find_packages(),
    install_requires=[
        "pycryptodome>=3.21.0",
    ],
    author="Elabsurdo984",
    author_email="matiassfernandez00@gmail.com",
    description="A comprehensive encryption/decryption library",
    long_description=open("README.md").read(),
    long_description_content_type="text/markdown",
    url="https://github.com/Elabsurdo984/EnDecrypter.git",
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: GPL License",
        "Operating System :: OS Independent",
    ],
    python_requires=">=3.12",
)