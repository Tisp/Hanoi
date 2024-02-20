FROM gcc:latest

COPY . /app
WORKDIR /app
run make
CMD ["./hanoi"]
