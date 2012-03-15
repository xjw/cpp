enum typeofCar = {compact, regular, handicapped}
enum typeofSpace = {compact, regular, handicapped}

class ParkingLot {
  int size;

  List<Lot> spaces;
  int findOpenSpace(typeofCar car_type);
  boolean isFull();
  
  // bonus
  // maintain a SortedMap or PriorityQueue to store the list of lots available
  // multithread syncronize on park/unpark
}

class Lot {
  boolean available;
  typeofSpace type;
  boolean isAvailable();
  double getDistance();
}

class car {
  typefCar type;
  void park();
  void unpark();
}
