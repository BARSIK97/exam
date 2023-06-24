FROM ubuntu

ENV TZ=Europe/Moscow
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update
RUN apt-get update
RUN apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools gcc -y
RUN apt-get install build-essential gcc -y

WORKDIR /MyProj_221-3210_Shakirov/
COPY *.cpp /MyProj_221-3210_Shakirov
COPY *.h /MyProj_221-3210_Shakirov
COPY *.pro /MyProj_221-3210_Shakirov



RUN qmake my_Program.pro
RUN make

ENTRYPOINT ["./my_Program"]