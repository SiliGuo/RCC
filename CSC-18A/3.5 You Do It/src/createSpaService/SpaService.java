//pg.150 You Do It
package createSpaService;

public class SpaService {
	private String serviceDescription;
	private double price;

	public void setServiceDescrioption(String service) {
		serviceDescription = service;
	}

	public void setPrice(double pr) {
		price = pr;
	}

	public String getServiceDescription() {
		return serviceDescription;
	}

	public double getPrice() {
		return price;
	}
}
