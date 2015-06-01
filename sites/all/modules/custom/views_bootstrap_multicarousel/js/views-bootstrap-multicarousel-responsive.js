/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

(function($){
    $(window).load(function(){sizeMultiCarousel()});
    $(window).resize(function(){sizeMultiCarousel()});
    
    
function sizeMultiCarousel(){
                            $('.carousel .item').each(function(){
                                $('div.row.clearfix.views-bootstrap-multicarousel-row').children().unwrap();
                                $('.views-bootstrap-multicarousel-front').remove();
                                $('.views-bootstrap-multicarousel-back').remove();
                                $('.hidden-xs').remove();
                            });
                            $('.carousel .item').each(function(){
                            
                            
                            /*
                             * no longer used as window width is unreliable.
                            var w = $(window).width();
                            var col = 0;
                            if(w < 992 && w >= 768){
                                col = 2;
                            }
                            if(w < 1200 && w >= 992){
                                col = 5;
                            }
                            if(w >= 1200){
                                col = 5;
                            }
                            */

                            var col = getNumberOfColumns();

                            //Check to see if this is the last item on the list.
                            //if so get the first item
                            var prev = $(this).prev();
                            if (!prev.length) {
                                    prev = $(this).siblings(':last');
                            }


                            //if we need more than one slide per item start to clone
                            
                                //prev.children(':first-child').clone().addClass('hidden-xs').appendTo($(this));

                                for (var i=0;i<col;i++) {
                                    
                                    switch(i){
                                        case 0:
                                            prev.children(':first-child').clone().addClass('hidden-xs').appendTo($(this));
                                        break;
                                        case 1:
                                            prev.children(':first-child').clone().addClass('hidden-xs').appendTo($(this));
                                        break;
                                        case 2:
                                            prev.children(':first-child').clone().addClass('hidden-xs hidden-sm').appendTo($(this));
                                        break;
                                        case 3:
                                            prev.children(':first-child').clone().addClass('hidden-xs hidden-sm').appendTo($(this));
                                        break;
                                        case 4:
                                            prev.children(':first-child').clone().addClass('hidden-xs hidden-sm').appendTo($(this));
                                        break;
                                    }
                                    
                                    prev=prev.prev();
                                    if (!prev.length) {
                                        prev = $(this).siblings(':last');
                                    }

                                }   
                            



                        });
                        $('.carousel .item').each(function(){
                            //prepare blank divs
                            var $newRow = $('<div/>').addClass('row clearfix views-bootstrap-multicarousel-row');
                            
                            var $blankFrontDiv = $('<div/>').addClass('col-xs-2 visible-xs-block views-bootstrap-multicarousel-front');

                            var $blankBackDiv = $('<div/>').addClass('col-xs-2 visible-xs-block views-bootstrap-multicarousel-back');

                            //now we append the blank divs to the front and back
                            $blankFrontDiv.prependTo($(this));
                            $blankBackDiv.appendTo($(this));
                            $(this).wrapInner($newRow);




                        });
                    }
                    
    function getNumberOfColumns(){
        var bool = $('#xs-indicator').is(':visible');
        if(bool){
            return 0;
        }
        
        bool = $('#sm-indicator').is(':visible');
        if(bool){
            return 2;
        }
        
        bool = $('#md-indicator').is(':visible');
        if(bool){
            return 5;
        }
        bool = $('#lg-indicator').is(':visible');
        if(bool){
            return 5;
        }
        //if for whatever reason nothing is visable we will only show 1 item in the carousel
        return 0;
    }
})(jQuery);