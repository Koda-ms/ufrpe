package questao04.negocio.beans;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class OfertaProduto implements Comparable<OfertaProduto>{
	
	private Loja loja;
	private Produto produto;
	private LocalDate data;
	private double precoOferta;
	private List<Produto> produtosEmOferta;

	public OfertaProduto(Loja loja, Produto produto, LocalDate data, double precoOferta) {
		this.setLoja(loja);
		this.setProduto(produto);
		this.setData(data);
		this.setPrecoOferta(precoOferta);
		this.produtosEmOferta = new ArrayList<>();
	}

	public Loja getLoja() {
		return loja;
	}

	public void setLoja(Loja loja) {
		if(loja != null) {
			this.loja = loja;
		}
	}

	public Produto getProduto() {
		return produto;
	}

	public void setProduto(Produto produto) {
		if(produto != null) {
			this.produto = produto;
		}
	}

	public LocalDate getData() {
		return data;
	}

	public void setData(LocalDate data) {
		if(data != null) {
			this.data = data;
		}
	}

	public double getPrecoOferta() {
		return precoOferta;
	}

	public void setPrecoOferta(double precoOferta) {
		if(precoOferta > 0) {
			this.precoOferta = precoOferta;
		}
	}

	public List<Produto> getProdutosEmOferta() {
		return produtosEmOferta;
	}

	public void setProdutosEmOferta(List<Produto> produtosEmOferta) {
		if(produtosEmOferta != null) {
			this.produtosEmOferta = produtosEmOferta;
		}
	}

	@Override
	public String toString() {
		return "OfertaProduto [loja=" + loja + ", produto=" + produto + ", data=" + data + ", precoOferta="
				+ precoOferta + ", produtosEmOferta=" + produtosEmOferta + "]";
	}
	
	//Compara os preços dos produtos para depois ordená-los
	@Override
	public int compareTo(OfertaProduto o) {
		return Double.compare(this.getPrecoOferta(), o.precoOferta);
	}
}
